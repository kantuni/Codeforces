fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val freq = s.groupingBy { it }.eachCount()
    var ok = false
    for (f in freq) {
        if (f.value > 1) {
            ok = true
            break
        }
    }
    val ans = if (n == 1 || ok) "Yes" else "No"
    println(ans)
}