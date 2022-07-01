module Leap exposing (isLeapYear)

isLeapYear : Int -> Bool
isLeapYear year =
    if (modBy 4 year) == 0 && not ((modBy 100 year) == 0) then
        True
    else
        if (modBy 400 year) == 0 then
            True
        else
            False
