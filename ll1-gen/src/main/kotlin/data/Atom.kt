package data
open class Atom(val name: String){

    override fun hashCode(): Int {
        return name.hashCode()
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (other !is Atom) return false

        if (name != other.name) return false

        return true
    }

    override fun toString(): String {
        return name
    }
}