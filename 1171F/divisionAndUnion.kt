import java.util.*
import kotlin.collections.ArrayList

class Event(val x: Int, val id: Int, val start: Boolean)

val xComparator = compareBy<Event> { it.x }
val xThenEndComparator = xComparator.thenByDescending { it.start }

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val events = ArrayList<Event>()
        val n = readLine()!!.toInt()
        for (j in 0 until n) {
            val (l, r) = readLine()!!.split(" ").map { it.toInt() }
            events.add(Event(l, j, true))
            events.add(Event(r, j, false))
        }
        Collections.sort(events, xThenEndComparator)
        val group = IntArray(n) { -1 }
        val active = mutableSetOf<Int>()
        var color = 0
        for (e in events) {
            if (e.start) {
                active.add(e.id)
            } else {
                active.remove(e.id)
            }
            if (active.size == 0) {
                color = (color + 1) % 2
            }
            if (group[e.id] == -1) {
                group[e.id] = color
            }
        }
        val total = group.sum()
        var ans = "-1"
        if (total in 1..n) {
            ans = group.map { it + 1 }.joinToString(" ")
        }
        println(ans)
    }
}
