/** Doubly linked list node class. */
class Node<T> {
  public data: any
  public next: Node<T> | null = null
  public prev: Node<T> | null = null
}

/**
 * Doubly linked list.
 * 
 * This implementation will not work when trying to operate on
 * an empty list.
 * 
 * Exercism tests are assuming that data stored in each node
 * is be unique (delete function).
 */
export class LinkedList<T> {
  private length = 0
  private head: Node<T> | null = new Node<T>
  private tail: Node<T> | null = new Node<T>

  /**
   * Creates a new node with data provided in data argument
   * and stores at the back of the list.
   * @param data Data that will be stored in a node.
   */
  public push(data: T): void {
    const n = new Node<T>
    n.data = data

    if(this.length === 0) {
      this.head = n
      this.tail = n
      n.next = null
      n.prev = null
    } else {
      n.next = null
      n.prev = this.head
      this.head = n
    }

    this.length++
  }

  /**
   * Creates a new node with data provided in data argument
   * and stores at the front of the list.
   * @param data Data that will be stored in a node.
   */
  public unshift(data: T): void {
    const n = new Node<T>
    n.data = data

    if(this.length === 0) {
      this.head = n
      this.tail = n
      n.next = null
      n.prev = null
    } else {
      if(this.tail !== null) {
        this.tail.prev = n
        n.next = this.tail
        n.prev = null
        this.tail = n
      }
    }

    this.length++
  }

  /**
   * Retreives data form the node at the back of the list
   * and removes this node.
   * @returns Data of type T stored in a node.
   */
  public pop(): T {
    const d: T = this.head?.data
    this.length--

    if(this.head !== null) {
      this.head = this.head.prev
    }

    return d
  }

  /**
   * Retreives data form the front node and removes this node.
   * @returns Data of type T stored in deleted node.
   */
  public shift(): T {
    const d: T = this.tail?.data
    this.length--

    if(this.tail !== null) {
      if(this.length === 1) {
        this.tail = this.head
      } else {
        this.tail = this.tail.next
      }
    }

    return d
  }

  /**
   * Delete node with data value provided in data argument.
   * @param data Data to be deleted.
   */
  public delete(data: T): void {
    let node = this.head

    do {
      if(node !== null) {
        if(node.data === data) {
          this.length--

          if(node.prev === null) { this.head = node.next }
          else { node.prev.next = node.next }
          if(node.next === null) { this.tail = node.prev }
          else { node.next.prev = node.prev }
          // because data in this case is unique we can break
          // from the loop after data is found and deleted
          break
        }

        node = node.prev
      }
    } while(node !== null)
  }

  /**
   * @returns Number of items in this list.
   */
  public count(): number {
    return this.length
  }
}
