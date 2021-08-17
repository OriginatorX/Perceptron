function buildPerceptron {
	if [ ! -d "$build" ]; then
		mkdir build
	fi
	cd build
	cmake -G "Visual Studio 16 2019" ..
	cmake --build .
}

buildPerceptron
