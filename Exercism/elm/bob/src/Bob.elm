module Bob exposing (hey)

hey : String -> String
hey remark =
    if String.isEmpty (String.trim remark) then
        "Fine. Be that way!"
    else if String.all Char.isUpper (String.filter Char.isAlpha remark) && String.endsWith "?" remark && String.any Char.isAlpha remark then
        "Calm down, I know what I'm doing!"
    else if not (String.any Char.isAlpha remark) && not (String.endsWith "?" (String.trim remark)) then
        "Whatever."
    else if String.all Char.isUpper (String.filter Char.isAlpha remark) && String.any Char.isAlpha remark then
        "Whoa, chill out!"
    else if String.endsWith "?" (String.trim remark) then
        "Sure."
    else
        "Whatever."
