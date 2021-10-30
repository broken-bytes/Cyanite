public class NativeArray<T>: Sequence, IteratorProtocol  {
    public typealias Element = T
    var data: UnsafeMutablePointer<T>
    public private(set) var count: Int
    private var seq: Int = 0

    public init(with array: inout [T]) {
        self.data = UnsafeMutablePointer<T>.allocate(capacity: array.count)
        self.data.initialize(from: &array, count: array.count)
        self.count = array.count
        self.seq = array.count
    }

    public func rawData() -> UnsafeMutablePointer<T> {
        return self.data
    }

    public subscript(index: Int) -> T {
        get {
            return self.data[index]
        }
        set(newValue) {
            self.data[index] = newValue
        }
}

    public func next() -> T? {
        if seq == 0 {
            return nil
        } else {
            defer {
                seq -= 1
            }
            return self.data[count - seq]
        }
    }  
}
