<?php

function toRna(string $_s) : string
{
    $_s = str_split($_s);

    $rna = '';
    for ($i = 0; $i < count($_s); $i++) {
        if ($_s[$i] == 'G') {
            $rna .= 'C';
        } elseif ($_s[$i] == 'C') {
            $rna .= 'G';
        } elseif ($_s[$i] == 'T') {
            $rna .= 'A';
        } elseif ($_s[$i] == 'A') {
            $rna .= 'U';
        }
    }

    return $rna;
}
