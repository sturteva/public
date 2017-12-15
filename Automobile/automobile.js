
function Automobile( year, make, model, type ){
    this.year = year; //integer (ex. 2001, 1995)
    this.make = make; //string (ex. Honda, Ford)
    this.model = model; //string (ex. Accord, Focus)
    this.type = type; //string (ex. Pickup, SUV)
    
    
   
}

Automobile.prototype.logMe = function(bool){
        
        if (bool){
            console.log(this.year,this.make, this.model,this.type);
            
        }
        
        else{
             console.log(this.year, this.make, this.model);
        }
    }

var automobiles = [ 
    new Automobile(1995, "Honda", "Accord", "Sedan"),
    new Automobile(1990, "Ford", "F-150", "Pickup"),
    new Automobile(2000, "GMC", "Tahoe", "SUV"),
    new Automobile(2010, "Toyota", "Tacoma", "Pickup"),
    new Automobile(2005, "Lotus", "Elise", "Roadster"),
    new Automobile(2008, "Subaru", "Outback", "Wagon"),
    ];

/*This function sorts arrays using an arbitrary comparator. You pass it a comparator and an array of objects appropriate for that comparator and it will return a new array which is sorted with the largest object in index 0 and the smallest in the last index*/
function sortArr( comparator, array ){
    
   for(var i = 0; i < array.length-1; i++){
       for(var j = 0; j < array.length-1-i; j++){
           if(!comparator(array[j], array[j+1])){
               var temp = array[j];
               array[j] = array[j+1];
               array[j+1] = temp;
           }
       }
    }
    return array;
}

/*A comparator takes two arguments and uses some algorithm to compare them. If the first argument is larger or greater than the 2nd it returns true, otherwise it returns false. Here is an example that works on integers*/
function exComparator( int1, int2){
    if (int1 > int2){
        return true;
    } else {
        return false;
    }
}

/*For all comparators if cars are 'tied' according to the comparison rules then the order of those 'tied' cars is not specified and either can come first*/

/*This compares two automobiles based on their year. Newer cars are "greater" than older cars.*/
function yearComparator( auto1, auto2){
    if(auto1.year > auto2.year){
        return true;
    }
    else{
        return false;
    }
}

/*This compares two automobiles based on their make. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function makeComparator( auto1, auto2){
    
    if(auto1.make.toUpperCase() < auto2.make.toUpperCase()){
        return true;
    }
    else{
        return false;
    }
}

/*This compares two automobiles based on their model. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function modelComparator( auto1, auto2){
    
    if(auto1.model.toUpperCase() < auto2.model.toUpperCase()){
        return true;
    }
    else{
        return false;
    }
}

/*This compares two automobiles based on their type. The ordering from "greatest" to "least" is as follows: roadster, pickup, suv, wagon, (types not otherwise listed). It should be case insensitive. If two cars are of equal type then the newest one by model year should be considered "greater".*/
function typeComparator( auto1, auto2){
    var auto1Type;
    var auto2Type;
    
    if(auto1.type.toUpperCase() === "ROADSTER"){
        auto1Type = 10;
    }
    
    else if(auto1.type.toUpperCase() === "PICKUP"){
        auto1Type = 9;
    }
    
    else if(auto1.type.toUpperCase() === "SUV"){
        auto1Type = 8;
    }
    
    else if(auto1.type.toUpperCase() === "SUV"){
        auto1Type = 7;        
    }
            
    else if(auto1.type.toUpperCase() === "WAGON"){
        auto1Type = 6;
    }
    
    else{
        auto1Type = 1;
    }
    
    if(auto2.type.toUpperCase() === "ROADSTER"){
        auto2Type = 10;
    }
    
    else if(auto2.type.toUpperCase() === "PICKUP"){
        auto2Type = 9;
    }
    
    else if(auto2.type.toUpperCase() === "SUV"){
        auto2Type = 8;
    }
    
    else if(auto1.type.toUpperCase() === "SUV"){
        auto2Type = 7;        
    }
            
    else if(auto2.type.toUpperCase() === "WAGON"){
        auto2Type = 6;
    }
    
    else{
        auto2Type = 1;
    }
    
    if(auto1Type > auto2Type){
        return true;
    }
    else{
        return false;
    }
}


console.log("*****");

console.log("The cars sorted by year are:");
var yearSort = sortArr(yearComparator,automobiles);
yearSort.forEach(function(element){element.logMe(false);});

console.log("The cars sorted by make are:");
var makeSort = sortArr(makeComparator,automobiles);
makeSort.forEach(function(element){element.logMe(false);});

console.log("The cars sorted by model are:");
var modelSort = sortArr(modelComparator,automobiles);
modelSort.forEach(function(element){element.logMe(false);});

console.log("The cars sorted by type are:");
var typeSort = sortArr(typeComparator,automobiles);
typeSort.forEach(function(element){element.logMe(true);});

console.log("*****");