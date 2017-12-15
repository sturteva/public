var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var router = express.Router();

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3456);

var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({extended:false}));
app.use(bodyParser.json());

app.get('/',function(req,res){
	var theRequest = {};	
	theRequest.type = "GET";
	var urlParams = [];
	for(var p in req.query){
		urlParams.push({'name':p,'value':req.query[p]});
	}
	if(urlParams.length > 0){
		theRequest.urlReceived = "URL Query:";
	}
	else{
		theRequest.urlReceived = "No URL Query";
	}
		theRequest.urlData = urlParams;
		res.render('home',theRequest); 
});

app.post('/',function(req,res){
	var theRequest = {};
	theRequest.type = "POST";
	var urlParams = [];
	for(var p in req.query){
		urlParams.push({'name':p,'value':req.query[p]});
        }
	if(urlParams.length > 0){
                theRequest.urlReceived = "URL Query:";
        }
        else{
                theRequest.urlReceived = "No URL Query";
        }

        
	theRequest.urlData = urlParams;
	
	var postParam = [];
	for(var p in req.body){
		postParam.push({'name':p,'value':req.body[p]}); 
	}

	theRequest.postReceived = "POST Request Info:"; 
	theRequest.postData = postParam;
	res.render('home',theRequest);						
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
