/*
  문제 : https://www.acmicpc.net/problem/11365
  풀이 : 뒤부터 출력한다. 코틀린 연습 문제
*/
import java.util.*

fun main(args:Array<String>)
{
    val sc: Scanner = Scanner(System.`in`)
    while(true)
    {
        var s = sc.nextLine()
        if(s=="END") break

        for(i in 0..s.length-1)
            print(s[s.length-1-i])
        println()
    }
}

