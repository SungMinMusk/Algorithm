/*
  문제 : https://www.acmicpc.net/problem/7366
  풀이 : 입력된 문자열에서 sheep (Sheep X!)의 갯수를 출력하는 간단한 문제이다.
*/
import java.util.*
import kotlin.system.exitProcess

fun main(args: Array<String>) = with(Scanner(System.`in`))
{
    var n = nextInt()
    for(z in 1..n)
    {
        var a = nextInt()
        var cnt = 0
        while(a-->0)
        {
            var s = next()
            if(s=="sheep") cnt++
        }
        println("Case $z: This list contains $cnt sheep.\n")
    }
}
