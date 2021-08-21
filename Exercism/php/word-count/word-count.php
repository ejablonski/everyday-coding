<?php
function wordCount(string $_s) : array
{
    $result = [];

    $_s = mb_strtolower($_s, 'utf-8');
    for ($i = 0; $i < strlen($_s); $i++) {
        if (!ctype_alnum($_s[$i]) || !ctype_print($_s[$i])) {
            $_s = str_replace($_s[$i], ' ', $_s);
        }
    }

    $_s = preg_replace('/([\s])\1+/', ' ', $_s);
    $_s = trim($_s);

    $arr = explode(' ', $_s);
    foreach ($arr as $word) {
        $word = preg_replace('/\s+/', '', $word);
        if (isset($result[$word])) {
            $result[$word]++;
        } else {
            $result[$word] = 1;
        }
    }

    return $result;
}
