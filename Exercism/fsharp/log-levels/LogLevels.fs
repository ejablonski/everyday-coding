module LogLevels

open System

let message (logLine: string): string =
    logLine.Replace("[ERROR]: ", "").Replace("[INFO]: ", "").Replace("[WARNING]: ", "").Trim()

let logLevel(logLine: string): string =
    logLine.Substring(1, logLine.IndexOf("]: ") - 1).ToLower()

let reformat(logLine: string): string =
    message logLine + " (" + logLevel logLine + ")"
