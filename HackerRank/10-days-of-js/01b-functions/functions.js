'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function factorial(number) {
    let ret = 1;
    for(var i = 1; i <= number; ++i) {
        ret *= i;
    }
    return ret;
}

function main() {
    const n = +(readLine());
    
    console.log(factorial(n));
}