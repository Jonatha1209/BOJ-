import Foundation
let line = readLine()!
let lineArr = line.components(separatedBy: " ")
let a = Int(lineArr[0])!
if a>=90{print("A")}
else if a>=80{print("B")}
else if a>=70{print("C")}
else if a>=60{print("D")}
else{print("F")}
