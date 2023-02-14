module LuciansLusciousLasagna exposing (elapsedTimeInMinutes, expectedMinutesInOven, preparationTimeInMinutes)

expectedMinutesInOven : Int
expectedMinutesInOven = 40

preparationTimeInMinutes : Int -> Int
preparationTimeInMinutes n =
    n * 2

elapsedTimeInMinutes : Int -> Int -> Int
elapsedTimeInMinutes n m =
    preparationTimeInMinutes n + m
