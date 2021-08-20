class Gigasecond {
  private indate: Date
  private gigasecond: number = 1000000000

  constructor(_date: Date) {
    this.indate = _date
  }

  date(): Date {
    return new Date(this.indate.getTime() + this.gigasecond * 1000)
  }
}

export default Gigasecond
