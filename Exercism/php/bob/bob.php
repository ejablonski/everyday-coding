<?php
class Bob
{
    public function respondTo(string $_s): string
    {
        // Get rid of whitespaces
        $_s = preg_replace('/\s+/', '', $_s);

        // check if all chars are uppercase (shouting)
        $shouting = true;
        for ($i = 0; $i < strlen($_s); $i++) {
            if (ctype_lower($_s[$i])) {
                $shouting = false;
                break;
            }
        }

        // check if string contains numbers (and punctual chars) only
        $numOnly = true;
        for ($i = 0; $i < strlen($_s); $i++) {
            if (!ctype_digit($_s[$i]) && !ctype_punct($_s[$i])) {
                $numOnly = false;
                break;
            }
        }

        if ($shouting && mb_substr($_s, -1) == '?' && !$numOnly) {
            return 'Calm down, I know what I\'m doing!';
        } else if ($shouting && !$numOnly && strlen($_s) > 0) {
            return 'Whoa, chill out!';
        } else if (mb_substr($_s, -1) == '?') {
            return 'Sure.';
        } else if (strlen($_s) == 0) {
            return 'Fine. Be that way!';
        }

        return 'Whatever.';
    }
}
