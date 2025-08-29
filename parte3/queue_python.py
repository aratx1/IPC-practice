from multiprocessing import Process, Queue

def productor(q):
    for i in range(1, 6):
        q.put(f"Mensaje {i}")

def consumidor(q):
    for i in range(5):
        print(q.get())

if __name__ == "__main__":
    q = Queue()
    p1 = Process(target=productor, args=(q,))
    p2 = Process(target=consumidor, args=(q,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
