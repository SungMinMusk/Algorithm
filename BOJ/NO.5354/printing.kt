/*
  문제 : https://www.acmicpc.net/problem/5354
  풀이 : 규칙대로 문자열을 출력한다.
*/
import java.math.BigInteger
import java.util.*
import kotlin.system.exitProcess

fun main(args:Array<String>)
{
    val sc: Scanner = Scanner(System.`in`)
    var n=sc.nextInt()
    while(n-->0)
    {
        var a=sc.nextInt()
        for(i in 1..a)
        {
            if(i==1 || i==a)
                for(j in 1..a)
                    print("#")
            else
            {
                print("#")
                for(j in 1..a-2)
                    print("J")
                print("#")
            }
            println()
        }
        println()
    }
}
