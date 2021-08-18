module TwoFer exposing (twoFer)

twoFer : Maybe String -> String
twoFer name =
    case name of
        Just a ->
            "One for " ++ a ++ ", one for me."

        Nothing ->
            "One for you, one for me."
