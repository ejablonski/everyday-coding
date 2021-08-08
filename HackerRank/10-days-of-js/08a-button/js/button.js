var btn = document.getElementById('btn');
btn.onclick = function() {
    let n = Number(btn.innerHTML);
    btn.innerHTML = n + 1;
};
