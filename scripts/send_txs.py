import requests
import random
import string


from multiprocessing.dummy import Pool as ThreadPool

def submit(n):
    N = 20
    j = 2*random.randint(0,1)
    print "Sending to ", 'http://localhost:%d/group/submit-transaction' % (9090 + j)
    res1 = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    res2 = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    bod = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))

    r = requests.post('http://localhost:%d/group/submit-transaction' % (9090 + j), json = {
        "resources": [res1, res2],
        "body":  bod
    })
    
    res1 = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    res2 = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    bod = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    
    r = requests.post('http://localhost:%d/group/submit-transaction' % (9090 + j + 1), json = {
        "resources": [res1, res2],
        "body":  bod
    })    


def submitParallel(numbers, threads=2):
    pool = ThreadPool(threads)
    results = pool.map(submit, numbers)
    pool.close()
    pool.join()
    return results

if __name__ == "__main__":
    r = requests.post('http://localhost:9090/mining-power/1', json = { })
    r = requests.post('http://localhost:9091/mining-power/1', json = { })    
    submitParallel(range(500), 20)

