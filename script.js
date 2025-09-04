function fetchData(query) {
  fetch(`/cgi-bin/backend.cgi?action=${query}`)
    .then(res => res.text())
    .then(data => document.getElementById('output').innerText = data);
}

function rentPrompt() {
  let id = prompt("Enter Car ID to rent:");
  let days = prompt("Enter number of days:");
  if (!id || !days) return;
  fetch(`/cgi-bin/backend.cgi?action=rent&id=${id}&days=${days}`)
    .then(res => res.text())
    .then(data => document.getElementById('output').innerText = data);
}

function buyPrompt() {
  let id = prompt("Enter Car ID to buy:");
  if (!id) return;
  fetch(`/cgi-bin/backend.cgi?action=buy&id=${id}`)
    .then(res => res.text())
    .then(data => document.getElementById('output').innerText = data);
}
