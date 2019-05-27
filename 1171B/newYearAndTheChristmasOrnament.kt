fun main() {
    val (y, b, r) = readLine()!!.split(" ").map { it.toInt() }
    var ans = 6
    for (i in y downTo 2) {
        if (b > i && r > i + 1) {
            ans = 3 * i + 3
            break
        }
    }
    println(ans)
}
