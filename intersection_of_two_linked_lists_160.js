const chalk = require('chalk');

function getIntersectionNode(intersectValVar, listAVar, listBVar, skipAVar, skipBVar) {
    let index1 = skipAVar;
    let index2 = skipBVar;

    if (index1 >= listAVar.length || index2 >= listBVar.length) {
        return false;
    }

    while (index1 < listAVar.length) {
        if (listAVar[index1] != listBVar[index2]) {
            return false;
        }
    
        index1++;
        index2++;
    }

    return true;
}

let intersectVal = [8,2,0]; 
let listA = [[4,1,8,4,5],[1,9,1,2,4],[2,6,4]];
let listB = [[5,6,1,8,4,5],[3,2,4],[1,5]];
let skipA = [2,3,3]; 
let skipB = [3,1,2];

for (let test = 0; test < intersectVal.length; test++) {
    console.log(chalk.green(`Test ${test + 1}:`), (getIntersectionNode(intersectVal[test], listA[test], listB[test], skipA[test], skipB[test]) ? `Intersected at ${intersectVal[test]}` : "No intersection"), "|");
}

