/*
  문제 : https://www.acmicpc.net/problem/3671
  풀이 : 에라토스테네스의 체와 백트랙킹을 이용한다.
*/
import java.util.*
var MAX = 10000005
var res = 0
var s = ""
var visit = arrayOfNulls<Boolean>(MAX)
var visit_index= arrayOfNulls<Boolean>(30)
var prime = arrayOfNulls<Boolean>(MAX)
fun eratos()
{
    var m = MAX-1
    prime[1]=false
    for(i in 2..m) prime[i] = true

    var i = 2
    while((i*i) <=m)
    {
        if(prime[i] == true)
            for(j in i*i..m step i)
                prime[j] = false
        i++
    }

}
fun ans(tmp:String)
{

    if(tmp.length>=1 && prime[tmp.toInt()]==true && visit[tmp.toInt()]==false)
    {
        visit[tmp.toInt()]=true
        res++
    }
    if(tmp.length == s.length) return
    for(i in 0..s.length-1)
    {
        var k=(tmp+s[i])
        if(visit_index[i] == false)
        {
            visit_index[i] = true
            ans(k)
            visit_index[i] = false
        }
    }

}
fun main(args:Array<String>)
{
    eratos()
    var sc = Scanner(System.`in`)
    var n = sc.nextInt()
    s=sc.nextLine()
    for(i in 1..n)
    {
        for(j in 0..MAX-1) visit[j] = false
        for(j in 0..29) visit_index[j] = false
        s=sc.nextLine()
        res=0
        ans("")
        println(res)
    }
}
