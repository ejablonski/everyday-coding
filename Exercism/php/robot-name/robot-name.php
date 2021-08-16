<?php
class Robot
{
    private $name;
    private $names = [];

    public function __construct()
    {
        $this->createName();
    }

    public function getName() : string
    {
        return $this->name;
    }

    public function reset() : string
    {
        $this->createName();

        if ($this->isValid($this->name)) {
            while (!$this->isValid($this->name)) {
                $this->createName();
            }
        }

        return $this->name;
    }

    private function createName()
    {
        $this->name = chr(rand(65, 90)) . chr(rand(65, 90)) . rand(0, 9) . rand(0, 9) . rand(0, 9);
        array_push($this->names, $this->name);
    }

    private function isValid(string $_name) : bool
    {
        if (in_array($_name, $this->names)) {
            return false;
        } else {
            return true;
        }
    }
}
