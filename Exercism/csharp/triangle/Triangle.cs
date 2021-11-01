using System;

public static class Triangle
{
    public static bool IsScalene(double side1, double side2, double side3)
    {
        // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
        if(!(Math.Max(side3, Math.Max(side1, side2)) < side1 + side2 + side3 - Math.Max(side3, Math.Max(side1, side2))))
        {
            return false;
        }

        if(side1 != side2 && side2 != side3 && side1 != side3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static bool IsIsosceles(double side1, double side2, double side3) 
    {
        // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
        if(!(Math.Max(side3, Math.Max(side1, side2)) < side1 + side2 + side3 - Math.Max(side3, Math.Max(side1, side2))))
        {
        return false;
        }

        if(
            side1 == side2 || side2 == side3 || side1 == side3 ||
            (side1 < side2 && side3 < side2 && side1 < side3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static bool IsEquilateral(double side1, double side2, double side3) 
    {
        // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
        if(!(Math.Max(side3, Math.Max(side1, side2)) < side1 + side2 + side3 - Math.Max(side3, Math.Max(side1, side2))))
        {
            return false;
        }

        if(side1 == side2 && side3 == side2 && side1 == side3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
