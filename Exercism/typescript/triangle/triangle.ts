export class Triangle {
  x: number = 0
  y: number = 0
  z: number = 0

  constructor(_x: number, _y: number, _z: number) {
    this.x = _x;
    this.y = _y;
    this.z = _z;
  }

  get isEquilateral() {
    // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
    if(!(Math.max(this.x, this.y, this.z) < this.x + this.y + this.z - Math.max(this.x, this.y, this.z))) {
      return false;
    }

    if(this.x == this.y && this.z == this.y && this.x == this.z) {
      return true;
    }
    else
    {
      return false;
    }
  }

  get isIsosceles() {
    // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
    if(!(Math.max(this.x, this.y, this.z) < this.x + this.y + this.z - Math.max(this.x, this.y, this.z))) {
      return false;
    }

    if(
      this.x == this.y || this.y == this.z || this.x == this.z ||
      (this.x < this.y && this.z < this.y && this.x < this.z)) {
      return true;
    }
    else
    {
      return false;
    }
  }

  get isScalene() {
    // https://en.wikipedia.org/wiki/Triangle_inequality#Euclidean_geometry
    if(!(Math.max(this.x, this.y, this.z) < this.x + this.y + this.z - Math.max(this.x, this.y, this.z))) {
      return false;
    }

    if(this.x != this.y && this.y != this.z && this.y != this.x) {
      return true;
    }
    else
    {
      return false;
    }
  }
}
