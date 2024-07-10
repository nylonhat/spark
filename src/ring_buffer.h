#ifndef RING_BUFFER_H
#define RING_BUFFER_H


template<typename T, size_t N>
struct RingBuffer{
	std::array<T, N> buffer = {};
	
	unsigned int count = 0;

	T& now(){
		return buffer[count % N];
	}

	T& next(){
		return buffer[(count+1) % N];
	}

	T& prev(int offset){
		return buffer[(count - offset) % N];
	}
	
	void rotate(){
		count++;
	}
};



#endif
