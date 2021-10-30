class NativeArray<T>: Sequence, IteratorProtocol  {
    var data: UnsafeMutablePointer<T>
    var count: Int

    init(with array: inout [T]) {
        self.data = UnsafeMutablePointer<T>.allocate(capacity: array.count)
        self.data.initialize(from: &array, count: array.count)
        count = array.count
    }

    func rawData() -> UnsafeMutablePointer<T> {
        return self.data
    }

    func next() -> T? {
        if count == 0 {
            return self.data[0]
        } else {
            defer { count -= 1 }
            return self.data[count]
        }
    }
}
