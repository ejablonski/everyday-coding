export class DnDCharacter {
  strength = DnDCharacter.generateAbilityScore()
  dexterity = DnDCharacter.generateAbilityScore()
  constitution = DnDCharacter.generateAbilityScore()
  intelligence = DnDCharacter.generateAbilityScore()
  wisdom = DnDCharacter.generateAbilityScore()
  charisma = DnDCharacter.generateAbilityScore()
  hitpoints = 10 + DnDCharacter.getModifierFor(this.constitution)

  constructor() {}

  public static generateAbilityScore(): number {
    let rolls = Array.from({ length: 4 }, () => Math.floor(Math.random() * 6))
    return rolls.reduce((a, b) => { return a + b }, 0) - Math.min(...rolls)
  }

  public static getModifierFor(abilityValue: number): number {
    return Math.floor((abilityValue - 10) / 2)
  }
}
