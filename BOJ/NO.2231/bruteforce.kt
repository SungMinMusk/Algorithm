/*
  문제 : https://www.acmicpc.net/problem/2231
  풀이 : 백만까지 완전탐색을 모두 구해본다!!
*/

import java.util.*
import kotlin.system.exitProcess

fun ans(a:String):String
{
    var sum = a.toInt()
    for(i in 0..a.length-1)
        sum+=a[i].toInt() - '0'.toInt()
    
    return sum.toString()
}
fun main(args:Array<String>)
{
    var sc=Scanner(System.`in`)
    var n = sc.nextInt()

    for(i in 1..1000000)
    {
        if(ans(i.toString()) == n.toString() )
        {
            print(i)
            exitProcess(0)
        }
    }
    print(0)
}
