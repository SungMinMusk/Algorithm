/*
  문제 : https://www.acmicpc.net/problem/14225
  풀이 : 모든 경우를 완전탐색한다! kotlin 연습 코드
*/
import java.util.*
import kotlin.system.exitProcess

var v = IntArray(100001) {0}
var arr = IntArray(2000001) {0}
var n:Int = 0

fun ans(idx:Int,sum:Int)
{
    arr[sum] = 1
    for(i in idx..n-1)
        ans(i+1,sum+v[i])
}
fun main(args:Array<String>)
{
    val sc: Scanner = Scanner(System.`in`)
    n = sc.nextInt()

    for(i in 0..n-1)
    {
        var a = sc.nextInt()
        v[i] = a
    }

    ans(0,0)
    for(i in 1..2000001)
    {
        if (arr[i] == 0)
        {
            print(i)
            exitProcess(0)
        }
    }

}
