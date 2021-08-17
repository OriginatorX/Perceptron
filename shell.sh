function buildPerceptron {
	if [ ! -d "$build" ]; then
		mkdir build
	fi
	cd build
	cmake -G "Visual Studio 16 2019" ..
	cmake --build .
}
echo "Building for Windows"
buildPerceptron
