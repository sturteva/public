document.addEventListener('DOMContentLoaded', bindButtons);
    
function bindButtons(){
    document.getElementById('weatherSubmit').addEventListener('click', function(event){
        var req = new XMLHttpRequest();
        var data;
        var apiReq;
            
        if(document.getElementById('city').value.length > 0){
            data = document.getElementById('city').value;
            apiReq = 'http://api.openweathermap.org/data/2.5/weather?q=';
            
        }
            
        else{
            data = document.getElementById('zip').value;
            apiReq = 'http://api.openweathermap.org/data/2.5/weather?zip='
        }
       
        req.open("GET", apiReq + data +'&units=imperial&appid=fa7d80c48643dfadde2cced1b1be6ca1', true);
        req.addEventListener('load', function(){
            if(req.status >= 200 && req.status <400){
                var response = JSON.parse(req.responseText);
                document.getElementById('cityName').textContent = response.name;
                document.getElementById('temp').textContent = response.main.temp + " F";
                document.getElementById('humidity').textContent = response.main.humidity + "%";   
            }
            else{
                console.log("Error in network request: " + req.statusText);
            }
        });
    
        req.send(null);     
        
        event.preventDefault();
    });
    
    document.getElementById('postSubmit').addEventListener('click', function(event){
        
        var req = new XMLHttpRequest();
        var newData = {postData:null};
        newData.postData = document.getElementById('postDat').value;
        req.open("POST",'http://httpbin.org/post',true);
        req.setRequestHeader('Content-Type', 'application/json');
        req.addEventListener('load', function(){
            
            if(req.status >= 200 && req.status <400){
                var response = JSON.parse(req.responseText);                
                var returnedData = JSON.parse(response.data);                
               
                document.getElementById('postResult').textContent = returnedData.postData;
            }
            else{
                console.log("Error in network request: " + req.statuesText);
            }
        });        
        req.send(JSON.stringify(newData));    
        event.preventDefault();
    });
}