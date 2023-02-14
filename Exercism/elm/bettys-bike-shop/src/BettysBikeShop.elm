module BettysBikeShop exposing (poundsToString, penceToPounds)

import String

penceToPounds : Float -> Float
penceToPounds pence =
    pence / 100


poundsToString : Float -> String
poundsToString pounds =
    "£" ++ String.fromFloat(pounds)
