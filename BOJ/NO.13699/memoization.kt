/*
  문제 : https://www.acmicpc.net/problem/13699
*/
import java.util.*

var arr = Array(40,{i->(i-i).toLong()})
fun ans(n:Int) : Long
{
    if(n==0) return 1.toLong()
    if(arr[n]!=0L) return arr[n]
    else
    {
        var sum = 0L
        for(i in 0..n-1)
            sum+=ans(i)*ans(n-1-i)
        arr[n]=sum
        return sum

    }
}
fun main(args:Array<String>)
{
    var sc=Scanner(System.`in`)
    var n =sc.nextInt()
    print(ans(n))
}
