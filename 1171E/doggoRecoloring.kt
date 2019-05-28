fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val freq = IntArray(26)
    for (c in s) {
        freq[c - 'a']++
    }
    var cnt = 0
    for (f in freq) {
        if (f > 1) {
            cnt++
        }
    }
    val ans = if (n == 1 || cnt > 0) "Yes" else "No"
    println(ans)
}