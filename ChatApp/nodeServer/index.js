// this file is node server which will handle socket io connection

// we are using 8000 port
const express = require('express');
const app = express();

const server = app.listen(8000, () => {
    console.log('Server listening on port 8000...');
});

// Serve static files from the public directory
app.use(express.static('../public'));


const io = require('socket.io')(server)                           // we are using 8000 port
const users = {};

io.on('connection', socket=>{                                   // jaise hi connection aayega socket me, then this arrow function will be executed
     
    // If any new user joins, let other users connected to the server know!
    socket.on('new-user-joined', name=>{                        // jaise hi socket ko 'new-user-joined' naam ka event milega, then vo yh wala function run kr dega
        users[socket.id] = name;                                // jo bhi new user hoga, usko hum users naam ki list me daal rhe hai 
        socket.broadcast.emit('user-joined', name);             // is line ke through, vo sbko bta dega ki new user ne join kiya hai, iss event ki madad se
    });
    // If someone sends a message, broadcast it to the other people
    socket.on('send', message =>{                  // agr kisi ne msg send kiya (ie agr 'send' naam ka event mila), then yh wala function run hoga
        socket.broadcast.emit('receive', {message: message, name: users[socket.id]})              // jab usse send naam ka event milega, then iss line ke through socket ek 'receive' naam ka event emit krega bakiyo ko (jisse send naam ka event mila tha, usse receive naam ka event nhi milega--broadcast.emit yhi krta hai) and ek object bhi bhejega
    });
    // If someone leaves the chat, let others know (here disconnect is a builtin event and baki events ke naam hmne hi define kiye hai)
    socket.on('disconnect', message=>{                        // jab koi user disconnect hoga (basically jab disconnect naam ka event milega node server ko), then this function will run 
        socket.broadcast.emit('left', users[socket.id]);      //  what is socket.id? --> every socket connection has a unique id
        delete users[socket.id];                              // jonsa user leave krega, uska socket id delete kr diya from user list
    });
// yh sabh events ke naam humne khud hi define kiye hai (except 'disconnect' which is a builtin event)
});
