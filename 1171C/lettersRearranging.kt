import java.util.Collections

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val s = readLine()!!
        var ans = if (s == s.reversed()) "-1" else s
        if (ans == "-1") {
            for (j in s.length - 1 downTo 1) {
                if (s[0] != s[j]) {
                    val sl = s.toMutableList()
                    Collections.swap(sl, 0, j)
                    ans = sl.joinToString("")
                    break
                }
            }
        }
        println(ans)
    }
}