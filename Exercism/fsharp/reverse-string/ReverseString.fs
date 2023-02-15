module ReverseString
open System

let reverse (input: string): string =
    String(input.ToCharArray() |> Array.rev)
