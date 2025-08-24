# Use a base image with Python and necessary build tools
FROM python:3.10-slim

# Set the working directory
WORKDIR /app

# Copy the source files
COPY CMakeLists.txt /app/
COPY cppFiles/ /app/cppFiles/
COPY Pybind11Submodule/ /app/Pybind11Submodule/
COPY pythonFiles/ /app/pythonFiles/
COPY requirements.txt /app/

#install all requirements
RUN pip install --no-cache-dir -r requirements.txt

# Install build dependencies for C++ and CMake
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    git \
    && rm -rf /var/lib/apt/lists/*


# Build the C++ module using CMake
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Add the build directory to the Python path so the module can be found
ENV PYTHONPATH="/app/build:${PYTHONPATH}"

# Install Google Chrome for selenium web automation
RUN apt-get update && apt-get install -y wget unzip
RUN wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
RUN apt install -y ./google-chrome-stable_current_amd64.deb
RUN apt-get clean


#Expose port
#EXPOSE 5000

# Run the Python script
CMD ["python3", "pythonFiles/python_client.py"]

