
const socket = io('http://localhost:8000');

// GET DOM elements in respective js variables (it is navigating a DOM)
const form = document.getElementById('send-container');
const messageInput = document.getElementById('messageInp');
const messageContainer = document.querySelector('.container');
var audio = new Audio('ting.mp3');


// It is function which will append event info to the container
let append = (message,position)=>{
    const messageElement = document.createElement('div');
    messageElement.innerText = message;
    messageElement.classList.add('message');        // basically messageElement naam ke div me 'message' class add ki hai
    messageElement.classList.add(position);         // basically messageElement naam ke div me position (left or right) class add ki hai
    messageContainer.append(messageElement);

    if(position=='left')                            // jab kisi doosre ka msg aaayega, to hi audio play hoga
    {
        audio.play();
    }
};

// Ask new user for his/her name 
const name = prompt("Enter your name to join");


// If a new user joins, let other knows (we are sending event to the server)
socket.emit('new-user-joined', name);               // phle hmne user ka name liya and fir hum iss line se hum socket ko ek 'new-user-joined' naam ka event de rhe hai (or emit kr rhe hai) and fir node server ko jab yh event milega, tab vo ek function run krega(that we have defined in index.js)


// If a new user joins, receive the event (basically its name) from the server
socket.on('user-joined',name=>{                     // socket on ho jayega (or listen kr rha hai) jab usse user-joined naam ka event milega and fir ek function run krega and uss event ke saath jo saaman (or data) aayega, usko data naam ke variable me store kiya hai
    append(`${name} joined the chat!`, 'right')

}) 


// If the server sends a message, receive it
socket.on('receive', data =>{                       // jab event 'receive' listen krega , tab uske saath ek object bhi, jisko hum yha pe data naam se receive kr rhe hai
    append(`${data.name}:${data.message}`, 'left')
}) 


// If user leaves the chat, append the info to the container
socket.on('left', name=>{
    append(`${name} left the chat`,'left');
})


// If the form gets submitted, send server the message
form.addEventListener('submit', (e)=>{               // jab bhi koi form submit krega, then yh wala function run ho jayega
    e.preventDefault();                              // yh line page ko reload hone se rokegi as form submit hone ke baad, page by default reload ho jata hai
    const message = messageInput.value;
    append(`You: ${message}`,'right');
    socket.emit('send', message);
    messageInput.value = '';
})