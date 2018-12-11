/*
  문제 : https://www.acmicpc.net/problem/10409
  풀이 : 모든 프로세스를 해결 가능한 경우를 주의!
*/

import java.util.*
import kotlin.system.exitProcess

fun main(args: Array<String>) = with(Scanner(System.`in`))
{
    var n = nextInt()
    var t = nextInt()
    var sum = 0

    for(i in 1..n)
    {
        var a = nextInt()
        sum+=a
        if(sum>t)
        {
            print(i-1)
            exitProcess(0)
        }
    }
    print(n)
}
