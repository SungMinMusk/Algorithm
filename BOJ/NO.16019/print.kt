/*
  문제 : https://www.acmicpc.net/problem/16019
  풀이 : 코틀린 연습용 문제, 출력문 연습
*/
import java.util.*

fun main(args:Array<String>)
{
    var sc=Scanner(System.`in`)
    var a=0
    var b=sc.nextInt()
    var c=sc.nextInt()
    var d=sc.nextInt()
    var e=sc.nextInt()
    println("$a $b ${b+c} ${b+c+d} ${b+c+d+e}")
    println("$b $a ${c} ${c+d} ${c+d+e}")
    println("${b+c} $c ${a} ${d} ${d+e}")
    println("${b+c+d} ${c+d} ${d} ${a} ${e}")
    println("${b+c+d+e} ${c+d+e} ${d+e} ${e} ${a}")
}
