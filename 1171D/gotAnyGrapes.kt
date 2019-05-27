fun main() {
    val (x, y, z) = readLine()!!.split(" ").map { it.toInt() }
    val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
    val andrew = a >= x
    val dmitry = (a - x + b) >= y
    val michal = (a - x + b - y + c) >= z
    val ans = if (andrew && dmitry && michal) "YES" else "NO"
    println(ans)
}