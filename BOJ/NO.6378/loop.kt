/*
  문제 : https://www.acmicpc.net/problem/6378
  풀이 : 한자리수가 될때까지 반복한다.
*/
import java.math.BigInteger
import java.util.*

fun ans(a:String)
{
    var b=a
    while(b.length>1)
    {
        var sum = 0
        for(i in 0..b.length-1)
        {
            sum+=b[i].toInt()-'0'.toInt()
        }
        b=sum.toString()
    }
    println(b)
}
fun main(args:Array<String>)
{
    var sc=Scanner(System.`in`)
    while(true)
    {
        var a = sc.nextLine()
        if(a=="0") break
        ans(a)
    }
}
