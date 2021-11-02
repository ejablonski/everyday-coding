export class DnDCharacter {
  strength: number = 0
  dexterity: number = 0
  constitution: number = 0
  intelligence: number = 0
  wisdom: number = 0
  charisma: number = 0
  hitpoints: number = 0

  constructor() {
    this.strength = DnDCharacter.generateAbilityScore()
    this.dexterity = DnDCharacter.generateAbilityScore()
    this.constitution = DnDCharacter.generateAbilityScore()
    this.intelligence = DnDCharacter.generateAbilityScore()
    this.wisdom = DnDCharacter.generateAbilityScore()
    this.charisma = DnDCharacter.generateAbilityScore()
    this.hitpoints = 10 + DnDCharacter.getModifierFor(this.constitution)
  }

  public static generateAbilityScore(): number {
    let rolls: number[] = [0, 0, 0, 0]

    for(let j = 0; j < 4; j++) {
      rolls[j] = Math.floor(Math.random() * 6);
    }

    return rolls.reduce(function(a, b) { return a + b; }, 0) - Math.min(...rolls)
  }

  public static getModifierFor(abilityValue: number): number {
    return Math.floor((abilityValue - 10) / 2);
  }
}
