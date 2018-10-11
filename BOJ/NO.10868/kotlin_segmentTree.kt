/*
  문제 : https://www.acmicpc.net/problem/10868
  풀이 : 코틀린 연습코드 : 세그먼트 트리
*/
import java.util.*

var INF = 0x7fffffff
var arr = IntArray (410000 ){INF}
var n=0
var m=0
var k=0

fun min(a:Int,b:Int) = if(a>b) b else a
fun MIN(L:Int,R:Int,node:Int,nl:Int,nr:Int) : Int
{
    if(R<nl || L>nr) return INF
    if(L <= nl && nr <= R) return arr[node]
    var mid = (nl+nr)/2
    return min(MIN(L,R,node*2,nl,mid),
            MIN(L,R,node*2+1,mid+1,nr))
}

fun update(i:Int,v:Int)
{
    var a=i
    arr[i]=v
    while(a>1)
    {
        a /= 2
        arr[a]=min(arr[a*2],arr[a*2+1])
    }
}
fun setting()
{
    var a=1
    while((a) < n)
        a*=2
    k=a
}
fun main(args:Array<String>)
{
    var sc=Scanner(System.`in`)
    n=sc.nextInt()
    m=sc.nextInt()
    setting()
    for(i in k..k+n-1)
    {
        var a = sc.nextInt()
        update(i,a)
    }
    for(i in 1..m)
    {
        var a= sc.nextInt()
        var b= sc.nextInt()
        println(MIN(a-1,b-1,1,0,k-1))
    }
}
