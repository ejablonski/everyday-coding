module LuciansLusciousLasagna

let expectedMinutesInOven = 40

let remainingMinutesInOven n =
    expectedMinutesInOven - n

let preparationTimeInMinutes n =
    n * 2

let elapsedTimeInMinutes n m =
    preparationTimeInMinutes n + m
