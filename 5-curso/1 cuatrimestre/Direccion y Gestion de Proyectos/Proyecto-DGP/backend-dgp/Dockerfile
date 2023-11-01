# Use an official Node.js runtime as the parent image
FROM node:16

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY package*.json ./

# Install the app dependencies
RUN npm install

# Copy the rest of the application code into the container
COPY . .

# Make the app available outside of the container
EXPOSE 3000

# Define the command to run the app
CMD ["node", "server.js"]
