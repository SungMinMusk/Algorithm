/* 
  문제 : https://www.acmicpc.net/problem/10870
  풀이 : 피보나치수의 점화식을 이용하여 bottom-up으로 구한다.
*/

import java.math.BigInteger
import java.util.*
import kotlin.system.exitProcess

fun main(args:Array<String>)
{
    val sc: Scanner = Scanner(System.`in`)
    var n=sc.nextInt()
    if(n==0)
    {
        println(0)
        exitProcess(0)
    }
    var n1 = 1
    var n2 = 1
    var n3 = 1
    for(i in 3..n)
    {
        n3=n1+n2
        n1=n2
        n2=n3
    }
    println(n3)
}
