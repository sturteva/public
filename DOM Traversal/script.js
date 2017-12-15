/*******************************************************************************************
**Author: Andrew P. Sturtevant
**Date: 28 Oct 2017
**Assignment: DOM & Events
**Description: Create a 4x4 table using JavaScript. Top Row is a Header Row, and contains
**Header 1-4.  The remaining cells contain their coordinates within the table.  4 Direction 
**buttons, that move the selected cell.  A mark button that marks a cell permanently yellow
********************************************************************************************/

var newTable = document.createElement("table");
newTable.id = "theTable";

for (var i = 0; i < 4; i++){
    var newRow = document.createElement("tr");
    for(var j = 0; j < 4; j++){
        if(i === 0){
            var newHeader = document.createElement("th");
            newHeader.textContent = "Header " +(j+1);
            newRow.appendChild(newHeader);
        }
        else{
            var newCell = document.createElement("td");
            newCell.textContent = (j+1) + ", " + i;
            newRow.appendChild(newCell);
        }
        
        newTable.appendChild(newRow);
    }
}
document.body.appendChild(newTable);

var upButton = document.createElement("button");
upButton.textContent = "Up";
upButton.id = "upButton";
var downButton = document.createElement("button");
downButton.textContent = "Down";
downButton.id = "downButton";
var leftButton = document.createElement("button");
leftButton.textContent = "Left";
leftButton.id = "leftButton";
var rightButton = document.createElement("button");
rightButton.textContent = "Right";
rightButton.id = "rightButton";

document.body.appendChild(upButton);
document.body.appendChild(downButton);
document.body.appendChild(leftButton);
document.body.appendChild(rightButton);

document.body.appendChild(document.createElement("div"));

var markButton = document.createElement("button");
markButton.textContent = "Mark Cell";
markButton.id = "markButton";
document.body.appendChild(markButton);

var selectedCell = document.getElementById("theTable").firstElementChild.nextElementSibling.firstElementChild;
selectedCell.style.borderStyle = "solid";

function moveLeft(){
    var theHomeList = selectedCell.parentNode.getElementsByTagName("td");
    
    if(theHomeList[0] === selectedCell){
        return;
    }
    else{
        selectedCell.style.borderStyle = "none";
        selectedCell = selectedCell.previousElementSibling;
        selectedCell.style.borderStyle = "solid";
    }
}

function moveRight(){
    var theHomeList = selectedCell.parentNode.getElementsByTagName("td");
    
    if(theHomeList[(theHomeList.length-1)] === selectedCell){
        return;
    }
    else{
        selectedCell.style.borderStyle = "none";
        selectedCell = selectedCell.nextElementSibling;
        selectedCell.style.borderStyle = "solid";
    }
}

function moveDown(){
    var theHomeList = selectedCell.parentNode.parentNode.getElementsByTagName("tr");
    
    if(theHomeList[(theHomeList.length-1)] === selectedCell.parentNode){        
        return;        
    }
    
    else{
        //Find Position of current selectedCell within the row.
        var pos = 0;
        var parentList = selectedCell.parentNode.getElementsByTagName("td");
        while(parentList[pos] != selectedCell){
            pos++;
        }
        
        selectedCell.style.borderStyle = "none";
        var newParentList = selectedCell.parentNode.nextElementSibling.getElementsByTagName("td");
        selectedCell = newParentList[pos];
        selectedCell.style.borderStyle = "solid";
        }
    
}

function moveUp(){
    var theHomeList = selectedCell.parentNode.parentNode.getElementsByTagName("tr");
    
    if(theHomeList[1] === selectedCell.parentNode){        
        return;        
    }
    
    else{
        //Find Position of current selectedCell within the row.
        var pos = 0;
        var parentList = selectedCell.parentNode.getElementsByTagName("td");
        while(parentList[pos] != selectedCell){
            pos++;
        }
        
        selectedCell.style.borderStyle = "none";
        var newParentList = selectedCell.parentNode.previousElementSibling.getElementsByTagName("td");
        selectedCell = newParentList[pos];
        selectedCell.style.borderStyle = "solid";
        }
    
}

document.getElementById("rightButton").addEventListener("click", moveRight);
document.getElementById("leftButton").addEventListener("click", moveLeft);
document.getElementById("downButton").addEventListener("click", moveDown);
document.getElementById("upButton").addEventListener("click", moveUp);
document.getElementById("markButton").addEventListener("click", 
                                                       function(){        selectedCell.style.backgroundColor = "yellow"});


